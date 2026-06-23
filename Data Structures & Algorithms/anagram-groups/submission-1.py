class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ret = defaultdict(list)
        for curr in strs:
            hash = [0] * 26
            for char in curr:
                hash[ord(char) - ord('a')] += 1
            ret[tuple(hash)].append(curr)
        return list(ret.values())