class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preMap = {i: [] for i in range(numCourses)}
        for elem in prerequisites:
            preMap[elem[0]].append(elem[1])

        visited = set()

        def dfs(i):
            if i in visited:
                return False
            if preMap[i] == []:
                return True
            visited.add(i)
            for pre in preMap[i]:
                if not dfs(pre):
                    return False
            visited.remove(i)
            preMap[i] = []
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False
        return True