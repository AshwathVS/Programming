class ParkingSystem {
public:
    int big, medium, small;

    ParkingSystem(int _big, int _medium, int _small) : big(_big), medium(_medium), small(_small) {};
    
    bool addCar(int carType) {
        if(carType == 1) {
            big--;
            return big>=0;
        } else if(carType == 2) {
            medium--;
            return medium>=0;
        } else {
            small--;
            return small>=0;
        }
    }
};
