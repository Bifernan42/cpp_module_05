CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes
SRCS = srcs/main.cpp srcs/Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = animals.exe

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
