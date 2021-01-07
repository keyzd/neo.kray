CXX := g++
CXXFLAGS := -g -Wall -O3
LDFLAGS := -lm
IMG_VIEWER = sxiv

BASE_DIR := src
SRC_MODULES := $(BASE_DIR)/main.cpp $(BASE_DIR)/NeoKray.cpp $(BASE_DIR)/Canvas.cpp $(BASE_DIR)/ICamera.cpp \
			   $(BASE_DIR)/DefaultRenderer.cpp \
			   $(BASE_DIR)/CameraPinhole.cpp \
			   $(BASE_DIR)/ObjectSphere.cpp $(BASE_DIR)/ObjectPlane.cpp $(BASE_DIR)/ObjectCylinder.cpp \
			   $(BASE_DIR)/MaterialPhong.cpp $(BASE_DIR)/MaterialNormalMap.cpp \
			   Scene1.cpp Scene2.cpp Scene3.cpp Scene4.cpp

OBJ_MODULES = $(SRC_MODULES:.cpp=.o)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

nkray: $(OBJ_MODULES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRC_MODULES)
	$(CXX) -MM $^ > $@

clean:
	rm -f *.o $(BASE_DIR)/*.o nkray
