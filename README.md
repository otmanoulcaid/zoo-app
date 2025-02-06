# Animal App

## Overview
The **Animal App** is a web-based system that manages animal data using **XML and XQuery** for storage and querying. It features a **C++ server** to handle HTTP requests and uses **Docker and Docker Compose** for easy deployment.

## Features
- **Store animal data in XML format**
- **Use XQuery to retrieve specific animal information**
- **C++ server to handle HTTP GET and POST requests**
- **Dockerized environment for easy deployment**

---

## Project Structure
```
/animal-app
│── data/
│   ├── xml/animal.xml  # XML Database
│   ├── xquery/         # XQuery scripts
│
│── serverWriter/
│   ├── ServerWriterr.hpp      # C++ Server Header
│   ├── ServerWriter.cpp      # C++ Server Implementation(to append xml in xml databse)
│   ├── main.cpp        # Entry point
│
│── xQueryServer/
│   ├── XQueryProcess.hpp      # C++ xQueryServer Header
│   ├── XQueryProcess.cpp     # C++ xQueryServer fork process
│   ├── Server.hpp      # C++ xQueryServer Header
│   ├── Server.cpp     # C++ xQueryServer Implementation
│   ├── main.cpp        # Entry point
│── Dockerfile
│── docker-compose.yml
│── Makefile            # Auto-compilation

```

---

## Setup & Installation

### 1️⃣ Prerequisites
- **Docker & Docker Compose** installed
- **GNU Make** for automatic compilation

### 2️⃣ Build & Run the Server
Using the Makefile, you can easily compile and run the server:
```sh
make build  # Compile the C++ server
make run    # Run the server
make clean  # Clean compiled files
```

### 3️⃣ Running with Docker
To run the entire application in a Dockerized environment, use:
```sh
docker-compose up --build
```
This will:
- Build the C++ server inside a container
- Expose the necessary ports
- Mount the XML data

---

## XML Data Format
Animal data is stored in an **XML file**:
```xml
<animals>
    <animal>
        <path>Holstein.jpeg</path>
        <id>13</id>
        <name>Holstein Cow</name>
        <espece>cow</espece>
        <race>Holstein</race>
        <description>Black-and-white dairy cows known for their high milk production.</description>
        <age>6</age>
        <proprietaire>Tom Harris</proprietaire>
    </animal>
</animals>
```

---

## XQuery Example
To retrieve all **birds** from the XML database:
```xquery
let $animaux := doc("../xml/animal.xml")/animals/animal[espece = 'bird']
let $navbar := doc("navbar.xquery")/navbar
return
    <html>
        <head>
            <link rel="stylesheet" href="css/bootstrap.min.css" />
            <link rel="stylesheet" href="css/main.css" />
            <link href="https://fonts.googleapis.com/css?family=Courgette" rel="stylesheet"/>
        </head>
        <body>
            { $navbar }
            <div class="container">
                <div class="row">
                    {
                    for $animal in $animaux
                    return
                        <div class="mx-auto col-md-6 col-lg-4">
                            <div class="featured-container p-5">
                                <img src="imgs/{ $animal/path }" class="img-fluid" alt="product"/>
                                <a href="#" class="featured-store-link text-capitalize">add to cart</a>
                            </div>
                            <h6 class="text-capitalize text-center my-2">special product</h6>
                            <h6 class="text-center">
                                <span class="text-muted old-price mx-2">$200</span>
                                <span>$100</span>
                            </h6>
                        </div>
                    }
                </div>
            </div>
        </body>
    </html>

```

---

## Handling HTTP Requests
The **C++ server** handles HTTP requests:

### Handling GET Requests
- Retrieves XML data based on **XQuery**
- Example request: `GET /all`
- Example request: `GET /birds`

### Handling POST Requests
- **Stores new animal data** in the XML file
- Automatically appends to `<animals>` before the last `</animals>` tag


---

## License
This project is **open-source** and available for modification and distribution.

🚀 **Enjoy working with the Animal App!** 🚀

