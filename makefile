COM = g++
SRCS = add_book.cpp  borrow_book.cpp main.cpp print_books.cpp  return_book.cpp  search_book.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(COM) -o $(TARGET) $(OBJS)
%.o: %.cpp
	$(COM) -c $< -o $@
clean:
	rm -f *.o $(TARGET)
