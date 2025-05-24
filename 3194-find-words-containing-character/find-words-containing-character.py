class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        ans=[]
        for v,i in enumerate(words):
            if x in i:
                ans.append(v)
        return ans