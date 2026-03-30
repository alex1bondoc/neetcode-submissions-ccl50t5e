class Solution:
    def encode(self, strs: List[str]) -> str:
        rez = []
        for s in strs: # Nu folosi 'str' ca nume, e keyword in Python
            # f-string e perfect aici
            rez.append(f"{len(s)}#{s}")
        return "".join(rez)

    def decode(self, s: str) -> List[str]:
        sol = []
        i = 0
        
        while i < len(s):
            # 1. Găsim unde este delimitatorul '#'
            j = i
            while s[j] != "#":
                j += 1
            
            # 2. Extragem lungimea (de la i până la j)
            # Ex: "12#..." -> s[i:j] este "12"
            length = int(s[i:j])
            
            # 3. Extragem string-ul efectiv
            # Datele încep după # (j + 1) și țin 'length' caractere
            word = s[j + 1 : j + 1 + length]
            sol.append(word)
            
            # 4. Mutăm pointerul i tocmai după string-ul curent
            # Pregătim pentru următorul cuvânt
            i = j + 1 + length
            
        return sol