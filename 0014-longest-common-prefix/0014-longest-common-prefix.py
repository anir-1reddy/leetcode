class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        strs.sort()
        s = ""
        i = 0
        length = len(strs)

        while i < len(strs[0]):
            if(strs[0][i]) == strs[length -1][i]:
                s += strs[0][i]
            else:
                break
            i += 1
        
        return s
        