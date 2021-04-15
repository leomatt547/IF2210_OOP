class GPoint<T extends Number>{
    private T x;
    private T y;

    public GPoint(T newx, T newy){
        x = newx;
        y = newy;
    }

    public GPoint(GPoint<T> g){
        x = g.x;
        y = g.y;
    }

    public T GetAbsis(){
        return this.x;
    }

    public T GetOrdinat(){
        return this.y;
    }

    public void SetAbsis(T newx){
        this.x = newx;
    }

    public void SetOrdinat(T newy){
        this.y = newy;
    }

    public int IsEqual(GPoint P){
        if((this.x == P.x)&&(this.y==P.y)){
            return 1;
        }else{
            return 0;
        }
    }
}