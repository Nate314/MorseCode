# Compiles the C++ sources with g++ (the Visual Studio project still builds on Windows),
# then runs the program once: it encodes and decodes a sample message and exits.
FROM gcc:14 AS build
WORKDIR /src
COPY *.cpp *.h ./
RUN g++ -std=c++17 -O2 -static -o morse *.cpp

FROM debian:bookworm-slim
WORKDIR /app
COPY --from=build /src/morse ./
# MorseCode reads dictionary.txt from the working directory.
COPY dictionary.txt ./
CMD ["./morse"]
