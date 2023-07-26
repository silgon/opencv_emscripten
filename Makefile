image-cpp:
	docker run --rm -it -v $${PWD}:/src silgon/opencv_emscripten:latest bash -c "em++ \`pkg-config --cflags --libs opencv4\` image.cpp -o image.js -O3 -s NO_EXIT_RUNTIME=1 -s \"EXPORTED_RUNTIME_METHODS=['ccall']\" -s ASSERTIONS=1  --bind"
image2-cpp:
	docker run --rm -it -v $${PWD}:/src silgon/opencv_emscripten:latest bash -c "em++ \`pkg-config --cflags --libs opencv4\` image2.cpp -o image2.js -O3 -s NO_EXIT_RUNTIME=1 -s \"EXPORTED_RUNTIME_METHODS=['ccall']\" -s ASSERTIONS=1  --bind"

#bash:  docker run --rm -it -v $PWD:/src silgon/opencv_emscripten:latest bash -c "em++ \`pkg-config --cflags --libs opencv4\` image.cpp -o image.js -O3 -s NO_EXIT_RUNTIME=1 -s \"EXPORTED_RUNTIME_METHODS=['ccall']\" -s ASSERTIONS=1  --bind"
