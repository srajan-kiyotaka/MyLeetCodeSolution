class ParkingSystem {
public:
    int _big, _medium, _small;
    ParkingSystem(int big, int medium, int small) {
        _big = big;
        _medium = medium;
        _small = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(_big == 0) return false;
            _big--;
            return true;
        }
        else if(carType == 2){
            if(_medium == 0) return false;
            _medium--;
            return true;
        }
        else{
            if(_small == 0) return false;
            _small--;
            return true;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */