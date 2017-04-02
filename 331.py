class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        uncompleted_roots = 0
        leaf = 0
        idx = 0
        tokens = preorder.split(',')
        token_len = len(tokens)
        for idx in range(token_len):
            if tokens[idx] == '#':
                if leaf==0:
                    leaf = 1
                else:
                    uncompleted_roots -= 1
                if uncompleted_roots == 0 and idx < token_len - 1:
                    return False
            else:
                uncompleted_roots += 1
        if uncompleted_roots == 0:
            return True
        else:
            return False