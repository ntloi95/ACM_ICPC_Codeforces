void tohop(int i) {
    for(int j = a[i-1]+1 ; j<=n-k+i ; j++ ) {
        a[i] = j ;
        if(i==k) {
            // tohop trong mang A
        }
        else {
            tohop(i+1) ;
        }
    }
}