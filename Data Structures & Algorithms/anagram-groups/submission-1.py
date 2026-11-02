class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)

        for word in strs:
            code = [0]*26
            for i in word:
                code[ord(i) - ord('a')] += 1
            res[tuple(code)].append(word)

        return list(res.values())
        