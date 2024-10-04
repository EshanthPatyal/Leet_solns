class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        count = 0
        skill.sort()
        i = 0
        j = len(skill) - 1
        curr = skill[0] + skill[j]
        while i < j:
            if skill[i] + skill[j] != curr:
                return -1
            
            count = count + skill[i]*skill[j]
            i+=1
            j-=1
    
        return count


