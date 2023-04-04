/*
Fonction qui substitue des éléments dans un mot de 24 bit divisé en 6 éléments de 4 bits 
grâce à des opérations bit à bit selon une boite de substitution box_s.
*/
int substit(int mot24, int* box_s){
    int modif= 0;
    int decal;
    int a;
    for(int i = 0; i < 6; i++) {
        decal = i * 4;
        a = (mot24 >> decal) & 0xf;
        modif = modif | (box_s[a] << decal);
    }
    return modif;
}

/*
Fonction qui permut des éléments dans un mot de 24 bit 
grâce à des opérations bit à bit selon une boite de permutation box_p.
*/
int permut(int mot24, int* box_p){
    int modif = 0;
    int a;
    for (int i = 0; i <24; i++){
        a = mot24 & 0x1;
        modif = modif | (a << (23 - box_p[23-i])  );
        mot24 = (mot24 >> 1);
        
    } 
    return modif;
}