/*“We can connect a Razor Page to an ASP.NET Web API using HttpClient. 
The PageModel sends HTTP requests such as GET or POST to the API, receives JSON data, and 
then passes that data to the Razor Page for display.”*/



//Razor Page — PageModel
//Products.cshtml.cs
public class ProductsModel : PageModel
{
    private readonly HttpClient _httpClient;

    public List<Product> Products { get; set; } = new();

    public ProductsModel(HttpClient httpClient)
    {
        _httpClient = httpClient;
    }

    // READ
    public async Task OnGetAsync()
    {
        Products = await _httpClient
            .GetFromJsonAsync<List<Product>>(
                "https://localhost:7001/api/products"
            ) ?? new();
    }

    // CREATE
    public async Task<IActionResult> OnPostCreateAsync(Product product)
    {
        await _httpClient.PostAsJsonAsync(
            "https://localhost:7001/api/products",
            product
        );

        return RedirectToPage();
    }

    // UPDATE
    public async Task<IActionResult> OnPostUpdateAsync(Product product)
    {
        await _httpClient.PutAsJsonAsync(
            $"https://localhost:7001/api/products/{product.Id}",
            product
        );

        return RedirectToPage();
    }

    // DELETE
    public async Task<IActionResult> OnPostDeleteAsync(int id)
    {
        await _httpClient.DeleteAsync(
            $"https://localhost:7001/api/products/{id}"
        );

        return RedirectToPage();
    }
}

/*Razor Page — UI
 Products.cshtml
@page
@model ProductsModel

<h1>Products</h1>

<!-- CREATE -->
<form method="post" asp-page-handler="Create">

    <input name="Name" placeholder="Product Name" />

    <input name="Price"
           type="number"
           placeholder="Price" />

    <button type="submit">
        Add Product
    </button>

</form>

<hr />

<!-- READ -->

@foreach (var product in Model.Products)
{
    <div>

        <strong>
            @product.Name
        </strong>

        <span>
            @product.Price
        </span>

        <!-- UPDATE -->
        <form method="post"
              asp-page-handler="Update"
              style="display:inline">

            <input type="hidden"
                   name="Id"
                   value="@product.Id" />

            <input name="Name"
                   value="@product.Name" />

            <input name="Price"
                   value="@product.Price" />

            <button type="submit">
                Update
            </button>

        </form>

        <!-- DELETE -->
        <form method="post"
              asp-page-handler="Delete"
              style="display:inline">

            <input type="hidden"
                   name="id"
                   value="@product.Id" />

            <button type="submit">
                Delete
            </button>

        </form>

    </div>
}
*/

/* Register HttpClient
   In Program.cs:


 builder.Services.AddHttpClient();
 var app = builder.Build();*/

//model
public class Product
{
    public int Id { get; set; }
    public string Name { get; set; }
    public decimal Price { get; set; }
}

[ApiController]
[Route("api/[controller]")]
public class ProductsController : ControllerBase
{
    private static List<Product> products = new()
    {
        new Product { Id = 1, Name = "Laptop", Price = 80000 },
        new Product { Id = 2, Name = "Mouse", Price = 1000 }
    };

    // GET: api/products
    [HttpGet]
    public IActionResult GetAll()
    {
        return Ok(products);
    }

    // GET: api/products/1
    [HttpGet("{id}")]
    public IActionResult GetById(int id)
    {
        var product = products.FirstOrDefault(x => x.Id == id);

        if (product == null)
            return NotFound();

        return Ok(product);
    }

    // POST: api/products
    [HttpPost]
    public IActionResult Create(Product product)
    {
        product.Id = products.Max(x => x.Id) + 1;
        products.Add(product);

        return Ok(product);
    }

    // PUT: api/products/1
    [HttpPut("{id}")]
    public IActionResult Update(int id, Product product)
    {
        var existing = products.FirstOrDefault(x => x.Id == id);

        if (existing == null)
            return NotFound();

        existing.Name = product.Name;
        existing.Price = product.Price;

        return Ok(existing);
    }

    // DELETE: api/products/1
    [HttpDelete("{id}")]
    public IActionResult Delete(int id)
    {
        var product = products.FirstOrDefault(x => x.Id == id);

        if (product == null)
            return NotFound();

        products.Remove(product);

        return Ok();
    }
}