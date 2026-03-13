cmake .. \
  -DBUILD_EXAMPLES=true -DBUILD_GRAPHICAL_EXAMPLES=true
  -DCMAKE_BUILD_TYPE=Release \
  -DOpenGL_GL_PREFERENCE=LEGACY \
  -DOPENGL_gl_LIBRARY=/usr/lib/aarch64-linux-gnu/libGL.so \
  -DOPENGL_glx_LIBRARY=/usr/lib/aarch64-linux-gnu/libGL.so \
  -DOPENGL_INCLUDE_DIR=/usr/include/GL 


cmake .. \
  -DBUILD_EXAMPLES=true -DBUILD_GRAPHICAL_EXAMPLES=true
  -DCMAKE_BUILD_TYPE=Release \
  -DOpenGL_GL_PREFERENCE=GLVND \
  -DOPENGL_gl_LIBRARY=/usr/lib/aarch64-linux-gnu/libGL.so \
  -DOPENGL_glx_LIBRARY=/usr/lib/aarch64-linux-gnu/libGL.so \
  -DOPENGL_INCLUDE_DIR=/usr/include/GL 
  
 cmake .. \
  -DBUILD_EXAMPLES=true -DBUILD_GRAPHICAL_EXAMPLES=true
  -DOpenGL_GL_PREFERENCE=GLVND \
  -DOPENGL_gl_LIBRARY=/usr/lib/aarch64-linux-gnu/libGL.so \
  -DOPENGL_glx_LIBRARY=/usr/lib/aarch64-linux-gnu/libGL.so \
  -DOPENGL_INCLUDE_DIR=/usr/include/GL 


make -j$(nproc)
sudo make install

rm -rf build   # 删除旧的构建文件夹
mkdir build
cd build

#######
cmake .. -DBUILD_EXAMPLES=true -DOpenGL_GL_PREFERENCE=LEGACY -DOPENGL_gl_LIBRARY=/usr/lib/aarch64-linux-gnu/libGL.so -DOPENGL_glu_LIBRARY=/usr/lib/aarch64-linux-gnu/libGLU.so -DOPENGL_INCLUDE_DIR=/usr/include/GL

