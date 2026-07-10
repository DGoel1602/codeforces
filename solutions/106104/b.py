def main():
    import sys
    input = sys.stdin.readline
    
    n, k = map(int, input().split())
    s = input().strip()
    
    # Prefix sum of wins
    wins = [0] * (n + 1)
    for i in range(1, n + 1):
        wins[i] = wins[i-1] + (1 if s[i-1] == 'W' else 0)
    
    result = []
    for _ in range(k):
        i, j = map(int, input().split())
        total = j - i + 1
        w = wins[j] - wins[i-1]
        l = total - w
        result.append("Y" if w > l else "N")
    
    print("".join(result))

if __name__ == "__main__":
    main()
