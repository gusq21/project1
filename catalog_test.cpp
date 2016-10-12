
#include "catalog.hpp"

#include <cassert>
#include <iostream>

using namespace std;

int main() {
  cout << "==== catalog.hpp ====" << endl;
  
  cout << "Product constructor" << endl;
  {
    // negative price should throw exception
    bool threw = false;
    try {
      Product<bool> p("123", "oats", -1.0);
    } catch (invalid_argument e) {
      threw = true;
    }
    assert(threw);

    Product<bool> works_fine("123", "oats", 1.0);
  }

  cout << "Product accessors" << endl;
  {
    Product<string> p("123", "oats", 1.0);
    assert(p.getCode() == "123");
    assert(p.getName() == "oats");
    assert(p.getPrice() == 1.0);
  }

  cout << "Catalog constructor" << endl;
  {
    Catalog<int> a(5), b(10);
    assert(a.getMaxProducts() == 5);
    assert(b.getMaxProducts() == 10);
	Catalog<string> a(5), b(10);
    assert(a.getNumProducts() == 0);
    assert(b.getNumProducts() == 0);

    bool threw = false;
    try {
      Catalog<bool> c(0);
    } catch (invalid_argument e) {
      threw = true;
    }
    assert(threw);

    threw = false;
    try {
      Catalog<bool> c(-1);
    } catch (invalid_argument e) {
      threw = true;
    }
    assert(threw);

    assert(!a.isFull<bool>());
    assert(!b.isFull<bool>());
  }

  cout << "Catalog gets full" << endl;
  {
    Catalog<int> a(2);
    assert(a.getMaxProducts() == 2);
    assert(a.getNumProducts() == 0);
    assert(!a.isFull());

    a.addProduct("100", "oats", 1.0);
    assert(a.getMaxProducts() == 2);
    assert(a.getNumProducts() == 1);
    assert(!a.isFull());

    a.addProduct("101", "groats", 2.0);
    assert(a.getMaxProducts() == 2);
    assert(a.getNumProducts() == 2);
    assert(a.isFull());

    bool threw = false;
    try {
      a.addProduct("102", "yolks", 3.0);
    } catch (overflow_error e) {
      threw = true;
    }
    assert(threw);
  }

  cout << "Catalog add and search for products" << endl;
  {
    Catalog<string> a(4);
    a.addProduct("100", "oats", 1.0);
    a.addProduct("101", "groats", 2.0);
    assert(a.getNumProducts() == 2);

    // try to add duplicate code
    bool threw = false;
    try {
      a.addProduct("101", "premium groats", 2.0);
    } catch (invalid_argument e) {
      threw = true;
    }
    assert(threw);
    assert(a.getNumProducts() == 2);
    
    a.addProduct("102", "soap", 3.0);
    a.addProduct("103", "rope", 4.0);

    // catalog already full
    assert(a.isFull());
    threw = false;
    try {
      a.addProduct("104", "tote", 5.0);
    } catch (overflow_error e) {
      threw = true;
    }
    assert(threw);

    // successfull searches
    assert(a.findCode("100").getName() == "oats");
    assert(a.findCode("101").getName() == "groats");
    assert(a.findCode("102").getName() == "soap");
    assert(a.findCode("103").getName() == "rope");

    // failed searches
    threw = false;
    try {
      a.findCode("999");
    } catch (exception e) {
      threw = true;
    }
    assert(threw);
  }

  cout << "Catalog uses heap memory" << endl;
  {
    Catalog<int> a(20*1000*1000); // 20 million is too big for the stack 
  }

  return 0;
}
