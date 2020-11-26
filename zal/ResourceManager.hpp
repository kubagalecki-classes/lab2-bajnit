#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
    
    ResourceManager(){  // Konstruktor domyślny
        dane = new Resource;
    }
    
    ResourceManager(const ResourceManager& rm){  //Konstruktor kopiujący
        dane = new Resource{*rm.dane};
    }
    
    ResourceManager(ResourceManager&& rm){  //Konstruktor przenoszący
        dane = rm.dane;
        rm.dane=nullptr;
    }
    
    ResourceManager& operator=(const ResourceManager& rm){  // kopiujacy przypisania
            
        if(&rm != this){
            delete dane;
            dane=new Resource{*rm.dane};
        }
        return *this;
    }
    
    ResourceManager& operator=(ResourceManager&& rm){  // przenoszący przypisania
        
        if(&rm != this){
            delete dane;
            dane=rm.dane;
            rm.dane=nullptr;
        }
        return *this;
    }
    
    
    ~ResourceManager(){  //destruktor
        delete dane;
    }
    
    double get(){ // funkcja zwracająca get
        return dane->get();
     }
    
private:
    Resource *dane; // klasa
};
