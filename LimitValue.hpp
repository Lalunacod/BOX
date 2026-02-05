#include <iostream>




template <typename T>

class LimitValue {
private:
    const T min_value;  
    const T max_value;  
    T current_value;    

    
    void limit() {
        if (current_value > max_value) {
            current_value = max_value;
        } else if (current_value < min_value) {
            current_value = min_value;
        }
    };

public:
   
    LimitValue(T min, T max, T init = T{}) 
        : min_value(min), max_value(max), current_value(init) {
        limit();
    };

    
    LimitValue<T>& operator=(const T& rhs) {
        current_value = rhs;
        limit();
        return *this;
    }

    
    LimitValue<T>& operator+=(const T& rhs) {
        current_value += rhs;
        limit();
        return *this;
    }

    
    LimitValue<T>& operator-=(const T& rhs) {
        current_value -= rhs;
        limit();
        return *this;
    }

    T val() const {
        return current_value;
    }
};



