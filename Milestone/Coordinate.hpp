#ifndef COORDINATE_HPP
#define COORDINATE_HPP

class Coordinate{
    public:
        Coordinate(){
            x = 0;
            y = 0;
        }
        Coordinate(int x, int y){
            this->x = x;
            this->y = y;
        }
        Coordinate(const Coordinate& c){
            x = c.x;
            y = c.y;
        }
        void operator=(const Coordinate& c){
            x = c.x;
            y = c.y;
        }

        void operator+(Coordinate c){
            return Coordinate(
                this->x + c.x,
                this->y + c.y
            );
        }

        ~Coordinate(){}
        int get_x() const{
            return x;
        }
        int get_y() const{
            return y;
        }
    private:
        int x;
        int y;
};

#endif