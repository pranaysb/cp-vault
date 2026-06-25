import os
import requests
import re
from collections import defaultdict
import json

VAULT_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# ==========================================
# CODEFORCES LOGIC
# ==========================================
def fetch_cf_problems():
    url = "https://codeforces.com/api/problemset.problems"
    try:
        response = requests.get(url, timeout=10)
        data = response.json()
        if data['status'] == 'OK':
            return data['result']['problems']
    except Exception as e:
        print(f"Error fetching Codeforces API: {e}")
    return []

def normalize_cf_name(name):
    return re.sub(r'[^a-zA-Z0-9]', '', name).lower()

def parse_cf_filename(filename):
    base = filename.rsplit('.', 1)[0]
    parts = base.split('_', 1)
    if len(parts) == 2:
        return parts[0], parts[1]
    return None, base

def process_codeforces():
    cf_dir = os.path.join(VAULT_DIR, "Codeforces")
    if not os.path.exists(cf_dir):
        return []
    
    problems = fetch_cf_problems()
    solved = []

    for root, _, files in os.walk(cf_dir):
        for filename in files:
            if not (filename.endswith('.cpp') or filename.endswith('.py') or filename.endswith('.java')):
                continue
                
            index, name_part = parse_cf_filename(filename)
            match = None
            if index and name_part:
                norm_target = normalize_cf_name(name_part)
                for p in problems:
                    if p.get('index') == index and normalize_cf_name(p.get('name', '')) == norm_target:
                        match = p
                        break
                if not match:
                    for p in problems:
                        if p.get('index') == index:
                            norm_p = normalize_cf_name(p.get('name', ''))
                            if norm_target and (norm_target in norm_p or norm_p in norm_target):
                                match = p
                                break
                                
            rel_path = os.path.relpath(os.path.join(root, filename), VAULT_DIR).replace("\\", "/")
            
            if match:
                solved.append({
                    'contestId': match.get('contestId', 'N/A'),
                    'index': match.get('index', 'N/A'),
                    'name': match.get('name', name_part),
                    'rating': match.get('rating', 'Unrated'),
                    'tags': match.get('tags', []),
                    'file_path': rel_path
                })
            else:
                solved.append({
                    'contestId': 'N/A',
                    'index': index if index else 'N/A',
                    'name': name_part,
                    'rating': 'Unrated',
                    'tags': [],
                    'file_path': rel_path
                })
    return solved

# ==========================================
# LEETCODE LOGIC
# ==========================================
def fetch_leetcode_problem(title_slug):
    url = "https://leetcode.com/graphql"
    query = """
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionFrontendId
        title
        titleSlug
        difficulty
        topicTags {
          name
        }
      }
    }
    """
    try:
        response = requests.post(url, json={'query': query, 'variables': {"titleSlug": title_slug}}, timeout=10)
        if response.status_code == 200:
            data = response.json()
            if 'data' in data and 'question' in data['data'] and data['data']['question']:
                return data['data']['question']
    except Exception as e:
        print(f"Error fetching LeetCode API for {title_slug}: {e}")
    return None

def process_leetcode():
    lc_dir = os.path.join(VAULT_DIR, "LeetCode")
    if not os.path.exists(lc_dir):
        return []
        
    solved = []
    for root, _, files in os.walk(lc_dir):
        for filename in files:
            if not (filename.endswith('.cpp') or filename.endswith('.py') or filename.endswith('.java')):
                continue
                
            base = filename.rsplit('.', 1)[0]
            # Expected format: 1_Two_Sum or Two_Sum
            parts = base.split('_', 1)
            if parts[0].isdigit() and len(parts) == 2:
                name_part = parts[1]
            else:
                name_part = base
                
            # Convert name to slug (e.g., Two_Sum -> two-sum)
            title_slug = name_part.lower().replace('_', '-')
            
            rel_path = os.path.relpath(os.path.join(root, filename), VAULT_DIR).replace("\\", "/")
            
            match = fetch_leetcode_problem(title_slug)
            
            if match:
                solved.append({
                    'id': match.get('questionFrontendId', ''),
                    'name': match.get('title', name_part),
                    'slug': match.get('titleSlug', title_slug),
                    'difficulty': match.get('difficulty', 'Unknown'),
                    'tags': [t['name'] for t in match.get('topicTags', [])],
                    'file_path': rel_path
                })
            else:
                solved.append({
                    'id': parts[0] if parts[0].isdigit() else '?',
                    'name': name_part.replace('_', ' '),
                    'slug': title_slug,
                    'difficulty': 'Unknown',
                    'tags': [],
                    'file_path': rel_path
                })
    return solved

# ==========================================
# GEEKSFORGEEKS LOGIC
# ==========================================
def process_gfg():
    gfg_dir = os.path.join(VAULT_DIR, "GFG")
    if not os.path.exists(gfg_dir):
        return []
        
    solved = []
    for root, _, files in os.walk(gfg_dir):
        for filename in files:
            if not (filename.endswith('.cpp') or filename.endswith('.py') or filename.endswith('.java')):
                continue
                
            # Directory should be Easy, Medium, or Hard
            difficulty = os.path.basename(root)
            if difficulty not in ["Easy", "Medium", "Hard"]:
                difficulty = "Unknown"
                
            base = filename.rsplit('.', 1)[0]
            name = base.replace('_', ' ')
            
            rel_path = os.path.relpath(os.path.join(root, filename), VAULT_DIR).replace("\\", "/")
            
            solved.append({
                'name': name,
                'difficulty': difficulty,
                'file_path': rel_path
            })
    return solved

# ==========================================
# MAIN GENERATOR
# ==========================================
def main():
    print("Processing Codeforces...")
    cf_solved = process_codeforces()
    
    print("Processing LeetCode...")
    lc_solved = process_leetcode()
    
    print("Processing GeeksforGeeks...")
    gfg_solved = process_gfg()

    # Generate README
    readme_path = os.path.join(VAULT_DIR, "README.md")
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write("# CP Vault \n\n")
        f.write("Welcome to my Competitive Programming and DSA vault!\n\n")
        f.write("> **Note**: This README is auto-generated by a GitHub Action.\n\n")
        
        # Codeforces Section
        if cf_solved:
            f.write("## 🚀 Codeforces\n")
            
            rating_counts = defaultdict(int)
            for p in cf_solved:
                rating_counts[p['rating']] += 1
            
            f.write("### Statistics\n")
            for r in sorted(rating_counts.keys(), key=lambda x: (isinstance(x, str), x)):
                f.write(f"- **{r}**: {rating_counts[r]} problems\n")
            
            f.write("\n### Solved Problems\n")
            f.write("| Problem | Rating | Tags | Solution |\n")
            f.write("|---------|--------|------|----------|\n")
            
            for p in sorted(cf_solved, key=lambda x: (isinstance(x['rating'], str), x['rating'])):
                if p['contestId'] != 'N/A':
                    prob_url = f"https://codeforces.com/contest/{p['contestId']}/problem/{p['index']}"
                    prob_link = f"[{p['contestId']}{p['index']} - {p['name']}]({prob_url})"
                else:
                    prob_link = f"{p['index']} - {p['name']}"
                    
                tags = ", ".join(p['tags'])
                sol_link = f"[Solution]({p['file_path']})"
                f.write(f"| {prob_link} | {p['rating']} | {tags} | {sol_link} |\n")
            f.write("\n")

        # LeetCode Section
        if lc_solved:
            f.write("## ⚡ LeetCode\n")
            
            diff_counts = defaultdict(int)
            for p in lc_solved:
                diff_counts[p['difficulty']] += 1
                
            f.write("### Statistics\n")
            for diff in ["Easy", "Medium", "Hard", "Unknown"]:
                if diff_counts[diff] > 0:
                    f.write(f"- **{diff}**: {diff_counts[diff]} problems\n")
            
            f.write("\n### Solved Problems\n")
            f.write("| ID | Problem | Difficulty | Tags | Solution |\n")
            f.write("|----|---------|------------|------|----------|\n")
            
            # Sort by ID if possible
            def sort_key(x):
                try:
                    return int(x['id'])
                except:
                    return 999999
            
            for p in sorted(lc_solved, key=sort_key):
                prob_url = f"https://leetcode.com/problems/{p['slug']}/"
                prob_link = f"[{p['name']}]({prob_url})"
                tags = ", ".join(p['tags'])
                sol_link = f"[Solution]({p['file_path']})"
                f.write(f"| {p['id']} | {prob_link} | {p['difficulty']} | {tags} | {sol_link} |\n")
            f.write("\n")

        # GFG Section
        if gfg_solved:
            f.write("## 💻 GeeksforGeeks\n")
            
            diff_counts = defaultdict(int)
            for p in gfg_solved:
                diff_counts[p['difficulty']] += 1
                
            f.write("### Statistics\n")
            for diff in ["Easy", "Medium", "Hard", "Unknown"]:
                if diff_counts[diff] > 0:
                    f.write(f"- **{diff}**: {diff_counts[diff]} problems\n")
            
            f.write("\n### Solved Problems\n")
            f.write("| Problem | Difficulty | Solution |\n")
            f.write("|---------|------------|----------|\n")
            
            for p in sorted(gfg_solved, key=lambda x: x['name']):
                sol_link = f"[Solution]({p['file_path']})"
                f.write(f"| {p['name']} | {p['difficulty']} | {sol_link} |\n")
            f.write("\n")

    print("README updated successfully.")

if __name__ == "__main__":
    main()
