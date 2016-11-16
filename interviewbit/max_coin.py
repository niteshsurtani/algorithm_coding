import pprint

def maxcoin(A):
    pp = pprint.PrettyPrinter(indent=4)

        num = len(A)

        dp = []
        
        for i in range(num):
            temp = []
            for j in range(num):
                temp.append((0,0))
            dp.append(temp)
        
        index = 0
        while(index < num):
            for ptr in range(0,num-index):
                i = ptr
                j = ptr + index

                if index == 0:
                    dp[i][j] = (A[i],0)
                elif index == 1:
                    dp[i][j] = (max(A[i],A[j]), min(A[i],A[j]))

                else:
                    poss1 = A[i] + dp[i+1][j][1]
                    poss2 = dp[i][j-1][1] + A[j]

                    if poss1 > poss2:
                        dp[i][j] = (poss1, dp[i+1][j][0])
                    else:
                        dp[i][j] = (poss2, dp[i][j-1][0])


            index += 1
    pp.pprint(dp)
    return dp[0][num-1][0]

print maxcoin([1,2,3,4,5,6])