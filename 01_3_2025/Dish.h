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


	void display() const;
	double getPrice() const;
	std::string getName() const;
};

