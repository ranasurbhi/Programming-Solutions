class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        count=0
        for i in range(len(arr)):
            for j in range(i+1,len(arr)):
                for k in range(j+1,len(arr)):
                    A=abs(arr[i]-arr[j])
                    B=abs(arr[j]-arr[k])
                    C=abs(arr[k]-arr[i])
                    if A<=a and B<=b and C<=c:
                        count+=1
        return count
