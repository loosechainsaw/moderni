Simple Modern Windows INI parser.

1. Open a stream
2. Create a reader
3. Get the results
4. Do what you want with it.
```
std::istream& stream = get_stream_to_read_from();
modern::windows::ini::reader reader;
std::vector<modern::windows::ini::section> results = reader.read();
```
