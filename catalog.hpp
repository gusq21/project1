
// catalog.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Classes that define a catalog of supermarket products.

#pragma once

#include <stdexcept>
#include <string>
#include <iterator>
using namespace std;
int n;

template <typename E>
class SNode {					// singly linked list node
private:
	E elem;					// linked list element value
	SNode<E> *next;				// next item in the list
};








// A product represents one particular kind of product, such as apples
// or cereal.
template <typename E>
class Product {
public:
public:
	
  // Create a product with a given code, name, and price.
  //
  // code is intended to be a UPC code (bar code) or PLU code in a
  // string.
  //
  // name may be any string.
  //
  // price is in units of dollars. It must be positive, or else this
  // function throws std::invalid_argument.
  Product(const std::string& code,
          const std::string& name,
          double price): code(code), name(name), price(price) {
     n=0;
    head = NULL;
    
    
    
    // TODO: implement this function properly
    throw std::invalid_argument("Price must be greater than 0");
  }

  ~Product() { 
	  SNode<E>* tmp = head;
	  while (current != 0) {
		  SNode<E>* next = current->next;
		  delete current;
		  current = next;
	  }
	  head = 0;
  
  }

  // Accessors.
  const std::string& getCode() const { return code; }
  const std::string& getName() const { return name; }
  double getPrice() const { return price; }
  
private:
  std::string code, name;
  double price;
  SNode<E>* head;				// head of the list
  int     n;
};

// A catalog represents a collection of all of the products available
// at a store.
template <typename E>
class Catalog {
public:

	// Iterator is a nested class within SNodeList<E>
	class Iterator {				// an iterator for the list
	public:
		E& get() {		// reference to the element
			return v->elem;
		}
		E& operator*() {		// reference to the element
			return v->elem;
		}
		bool operator==(const Iterator& p) const {	// compare positions
			return v == p.v;
		}
		bool operator!=(const Iterator& p) const {
			return v != p.v;
		}
		Iterator& operator++() {		// move to next position
			v = v->next; return *this;
		}
		friend class Catalog;			// give NodeList access
	private:
		SNode<E>* v;					// pointer to the node
		Iterator(SNode<E>* u) {		// constructor from SNode*
			v = u;
		}
	};
	// Create a new catalog.
	//
	// maxProducts is the maximum number of products that can be
	// stored. It must be positive, or else this function throws
	// std::invalid_argument.
	Catalog() {
		head = NULL;
		n = 0;
		// TODO: implement this function properly
		throw std::invalid_argument("There must a positive number of products");
	}

	~Catalog() {
		bool empty() {
			if (n == 0) {
				Return true;
				Else return false;
			}
			// TODO: implement this function properly
			throw std::logic_error("not implemented yet");
		}
	}

	// Accessors.
	//template <typename E>
	int getMaxProducts() const {
		E maxProducts = -1;
		for (int i = 0; i < n; i++) {
			if (maxProducts < products[i])
				maxProducts = products[i];
			return maxProducts;



			// TODO: implement this function properly
			throw std::logic_error("not implemented yet");
		}

		int getNumProducts() const {
			int numberOfProducts = 0;
			if (head != 0) {
				for (Iterator i = ds.begin(); i = ds.end(); i++)
					numberOfProducts++;
				

			}
				return numberOfProducts;
			// TODO: implement this function properly
			throw std::logic_error("not implemented yet");
		}

		// Return true when the catalog cannot fit any more products.
		bool isFull(maxProducts) const {
			if (maxProducts = TRUE) {
					// TODO: implement this function properly
					throw std::logic_error("not implemented yet");
			}
		}

		// Add a new product to the catalog with a given code and name.
		//
		// code, name, and price have the same meaning as in a Product. If
		// price is invalid, throw std::invalid_argument.
		//
		// If this catalog is already full, throw overflow_error.
		//
		// Code must be different from all the product codes already in the
		// database. If it's not, throw std::invalid_argument.
		void addProduct(const std::string& code,
			const std::string& name,
			double price) {
			while (cur->next && (val >= cur->next->val))
			{
				cur = cur->next;
			}

			if (val == cur->val)
			{
				throw std::invalid_argument("This is a duplicate code")
				return;
			}
		
			// TODO: implement this function properly

			throw std::overflow_error("The catalog is already full");
		}

		// Find a product by its code.
		//
		// code is a product code.
		//
		// Returns a const reference to the product with the matching code.
		//
		// Throw std::invalid_argument if no product with that code exists
		// in the catalog.
		const Product& findCode(const std::string& code) const {
			
			

			while (cur->next && (val >= cur->next->val))
			{
				cur = cur->next;
				return code;
				cout >> "Enter a product code";
				cin << pCode;
				if (code == pCode) {
					return Product;
				}
				if (code != = cin << "") throw std::invalid_argument("The code doesn't exist in the catalog");
			}
			
			// TODO: implement this function properly
		}

private:
	SNode<E> *head;
	int n;
	// TODO: add data members
	};
};

