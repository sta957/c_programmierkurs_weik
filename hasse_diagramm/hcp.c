int hcp(int z){
    int x = z;
    int i = 0;
    while(x != 1){
        if(x % 2 == 0 && x != 0){
            x = x/2;
        }else{
            x = (3*x)+1;
        }
        i++;
    }
    return i;
}
