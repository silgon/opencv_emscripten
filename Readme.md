# OPENCV_EMSCRIPTEN
This project was created as a starting point to develop opencv with webassembly. We use only the function [Canny Edge Detector](https://en.wikipedia.org/wiki/Canny_edge_detector).
The binaries are not in the repository, please create them with the following command.

```bash
docker push silgon/opencv_emscripten
```

This will download an image of opencv with emscripten I created. You can find more information [here](https://github.com/silgon/dockerfiles/tree/master/opencv_emscripten).

```bash
make image-cpp
make image2-cpp
```

Then just run a http server on the root directory and enter one of the following files.

- **image.html** : version calling 
- **webcam.html** : webcam version of the `image.html` file, it won't work propertly because of memory overflow (that's why I have `image2.html` and `webcam2.html`
- **image2.html** : version with `cv::Mat` objects that live in javascript
- **webcam2.html** : version with `cv::Mat` objects that live in javascript. Unlike `webcam.html`, this version does not have memory issues.

To run the http server, these are some commands that you can try.
```bash
emrun . --no_browser
```

```bash
python -m http.server 
```
