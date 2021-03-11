#ifndef COORDINATE_HPP
#define COORDINATE_HPP

template<class T>
class Coordinate{
    public:
        Coordinate(){
            x = 0;
            y = 0;
        }
        Coordinate(T x, T y){
            this->x = x;
            this->y = y;
        }
        Coordinate(const Coordinate<T>& c){
            x = c.x;
            y = c.y;
        }
        void operator=(const Coordinate<T>& c){
            x = c.x;
            y = c.y;
        }

        Coordinate<T> operator+(Coordinate<T> c){
            return Coordinate<T>(
                this->x + c.x,
                this->y + c.y
            );
        }

        ~Coordinate(){}
        T get_x() const{
            return x;
        }
        T get_y() const{
            return y;
        }
    private:
        T x;
        T y;
};

#endif