class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        mp = {i:[] for i in range(numCourses)}

        for crs, pre in prerequisites:
            mp[crs].append(pre)

        visiting = set()

        def dfs(crs):
            if crs in visiting:
                return False

            if mp[crs] == []:
                return True

            visiting.add(crs)

            for pre in mp[crs]:
                if not dfs(pre):
                    return False
                
            visiting.remove(crs)
            mp[crs] = []
            return True

        for c in range(numCourses):
            if not dfs(c):
                return False
            
        return True
        