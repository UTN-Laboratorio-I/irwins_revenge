#include <iostream>
#include <chrono>
using namespace std;
void portadaPrincipal(){

    cout <<"_|_|_|  _|_|_|    _|          _|  _|_|_|  _|      _|  _|    _|_|_|  "<<endl;
    cout <<"  _|    _|    _|  _|          _|    _|    _|_|    _|      _|        "<<endl;
    cout <<"  _|    _|_|_|    _|    _|    _|    _|    _|  _|  _|        _|_|    "<<endl;
    cout <<"  _|    _|    _|    _|  _|  _|      _|    _|    _|_|            _|  "<<endl;
    cout <<"_|_|_|  _|    _|      _|  _|      _|_|_|  _|      _|      _|_|_|    "<<endl;
    cout <<endl<<endl;
    cout <<"_|_|_|    _|_|_|_|  _|      _|  _|_|_|_|  _|      _|    _|_|_|  _|_|_|_|  "<<endl;
    cout <<"_|    _|  _|        _|      _|  _|        _|_|    _|  _|        _|        "<<endl;
    cout <<"_|_|_|    _|_|_|    _|      _|  _|_|_|    _|  _|  _|  _|  _|_|  _|_|_|    "<<endl;
    cout <<"_|    _|  _|          _|  _|    _|        _|    _|_|  _|    _|  _|        "<<endl;
    cout <<"_|    _|  _|_|_|_|      _|      _|_|_|_|  _|      _|    _|_|_|  _|_|_|_| "<<endl;
std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "\x1b[2J\x1b[H";


    
}