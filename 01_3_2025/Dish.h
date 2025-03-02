class Dish {
protected:
	std::string name;
	double price;
public:
	Dish(std::string dishName, double dishPrice);
	Dish(const Dish& other);
	Dish& operator=(const Dish& other);
	Dish(Dish&& other) noexcept;
	Dish& operator=(Dish&& other) noexcept;
	Dish::Dish(std::string dishName, double dishPrice)
    : name(std::move(dishName)), price(dishPrice) {}

Dish::Dish(const Dish& other)
    : name(other.name), price(other.price) {}

Dish& Dish::operator=(const Dish& other) {
    if (this != &other) {
        name = other.name;
        price = other.price;
    }
    return *this;
}

Dish::Dish(Dish&& other) noexcept
    : name(std::move(other.name)), price(other.price) {}

Dish& Dish::operator=(Dish&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        price = other.price;
    }
    return *this;
}


	void display() const;
	double getPrice() const;
	std::string getName() const;
};

