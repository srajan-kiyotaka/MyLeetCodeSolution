class Solution:
    def bestNumbers(self, N : int, A : int, B : int, C : int, D : int) -> int:
        MOD = 10**9+7
        def _satisfy(v):
            while v:
                v, r = divmod(v, 10)
                if not(r==C or r==D): return False
            return True
        def _fact(n):
            ans, tmp = [1]*(n+1), 1
            for i in range(2, n+1):
                tmp = (tmp*i) % MOD
                ans[i] = tmp
            return ans
            
        # if A==B: return 1 if _satisfy(N*A) else 0
        ans = 0
        facts = _fact(N)
        for acnt in range(N+1):
            bcnt = N-acnt
            dsum = A*acnt + B*bcnt
            if not _satisfy(dsum): continue
            down = (facts[acnt] * facts[bcnt]) % MOD
            inv = pow(down, MOD-2, MOD)
            ans = (ans + facts[N] * inv) % MOD
        return ans
        



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        N = int(input())
        
        
        A = int(input())
        
        
        B = int(input())
        
        
        C = int(input())
        
        
        D = int(input())
        
        obj = Solution()
        res = obj.bestNumbers(N, A, B, C, D)
        
        print(res)
        

# } Driver Code Ends