bool isPowerOfTwo(int n) {
    if(n<1){
        return false;
    }
    else if(n == 1)
    {
        return true;
    }
    if(n%2 == 0)
    {
        return isPowerOfTwo(n/2);
    }
    else{
        return false;
    }
}