n = int(input())
s = input()
s2 = ""
for i in range(n-1):
   s2 += s[i]
   if s[i] == ')' and s[i+1] == '(':
       s2 += '*'
   if s[i] == '(' and s[i+1] == ')':
       s2 += '1'
   if s[i] == ')' and s[i+1] == ')':
       s2 += '+1'
s2 += s[-1]
print(eval(s2))
