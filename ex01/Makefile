SRCS =  main.cpp \
		Bureaucrat.cpp\
		Form.cpp\
		
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Form

OBJ =  $(SRCS:.cpp=.o)

%.o : %.cpp Bureaucrat.hpp Form.hpp
	@c++ $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $@

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all