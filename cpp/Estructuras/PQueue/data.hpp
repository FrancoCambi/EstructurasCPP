#ifndef __DATA_HPP__
#define __DATA_HPP__

template<typename tipo>
// If tipo isn't a pointer, do nothing.
static void deleteData(tipo data) { return; }

template<typename tipo>
// OVERLOAD -> if tipo is a pointer, delete it.
static void deleteData(tipo* data) { delete data; }

template<class tipo>
// Data representation. Stores data and its priority.
class Data {

    private:
        tipo data;
        unsigned int priority;
    
    public:

        // CONSTRUCTOR
        Data(tipo val, unsigned int prio);

        // DESTRUCTOR
        ~Data() {
            deleteData(data);
        }

        // PRIO GETTER
        unsigned int getPriority() {
            return priority;
        }

        // DATA GETTER
        tipo getData() {
            return data;
        }
};

template<class tipo>
// CONSTRUCTOR
Data<tipo>::Data(tipo val, unsigned int prio) {

    data = val;
    priority = prio;
}

#endif /* __DATA_HPP__ */