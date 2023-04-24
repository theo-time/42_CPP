#ifndef Brain_HPP
#define Brain_HPP
#include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define GREEN "\001\033[1;32m\002"
# define BOLD "\033[1;90m"
# define GRAY_S "\033\001[0;90m\002"

class Brain {

  private:
    std::string  _ideas[100];

  public:
    Brain();
    Brain(const Brain &Brain);
    Brain& operator=(const Brain &Brain);
    virtual ~Brain();

    void printIdeas();

    /* Getters and setters */
    std::string* getIdeas() const;
    void setIdea(int i, std::string idea);
};

#endif