# Compilador i flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Troba automàticament tots els fitxers .cpp a la carpeta actual
SRCS = $(wildcard *.cpp)

# Converteix la llista de .cpp en una llista de fitxers objecte .o
OBJS = $(SRCS:.cpp=.o)

# Nom de l'executable final
TARGET = testPark

# Regla principal que s'executa en fer "make"
all: $(TARGET)

# Enllaça tots els fitxers .o per crear l'executable final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla genèrica per compilar qualsevol .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla per netejar el directori (esborra els .o i l'executable)
clean:
	rm -f $(OBJS) $(TARGET)

# COMMANDS:
# 	Compilar: make
#	Executar: ./TestPark
#	Netejar fitxers binaris/objectes: make clean