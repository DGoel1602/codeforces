def main(init, sec, var):
    ans = 0

    def sgn(x):
        if(x > 0):
            return 1
        if(x < 0):
            return -1
        return 0
        

    for i in range(int(init[0]), int(init[1]), int(init[2])):
        sec2 = sec[::]
        for w in range(3):
            if sec2[w] == var:
                sec2[w] = str(i)
        # print(sec2, var, sec)
        num = int(sec2[1])-int(sec2[0])+int(sec2[2])
        cnt2 = max((num-sgn(num))//int(sec2[2]), 0)
        ans += cnt2 * (int(sec2[0])) + ((cnt2)*(cnt2-1)//2) * int(sec2[2])
        # print(cnt2, sec2, ans, cnt2 * (i if sec[0] == var else int(sec[0])) + ((cnt2)*(cnt2-1)/2) * (i if sec[1] == var else int(sec[1])) , i)
    print(int(ans))

a = input()
a = input()
var = a[4]
a = a[15:-2]
init = list(a.split(","))
if(len(init) == 2):
    init.append("1")
a = input()
a = a[19:-2]
sec = list(a.split(","))

if(len(sec) == 2):
    sec.append("1")
main(init, sec, var)
    

# ['1', '1', '4'] q ['4', 'q', '1']
# 0 ['1', '1', '4'] 0.0 0.0 1
# ['1', '6', '4'] q ['4', 'q', '1']
# 2 ['1', '6', '4'] 6.0 14.0 6
# ['1', '11', '4'] q ['4', 'q', '1']
# 3 ['1', '11', '4'] 21.0 45.0 11
# ['1', '16', '4'] q ['4', 'q', '1']
# 4 ['1', '16', '4'] 49.0 112.0 16
# 49
