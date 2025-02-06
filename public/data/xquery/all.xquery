let $animaux := doc("../xml/animal.xml")/animals/animal
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
                                <a href="#" class="featured-store-link text-capitalize" onclick="details('{ $animal/id }')">see details</a>
                            </div>
details
                            <h6 class="text-capitalize text-center my-2">{ $animal/name }</h6>
                            <h6 class="text-center">
                                <span class="text-muted old-price mx-2">$200</span>
                                <span>$100</span>
                            </h6>
                        </div>
                    }
                </div>
            </div>
			<script src="js/script.js"></script>
        </body>
    </html>
