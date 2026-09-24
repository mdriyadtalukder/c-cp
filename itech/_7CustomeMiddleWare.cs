
/*Custom middleware is middleware that you create yourself when ASP.NET Core's built-in middleware 
doesn't provide the exact behavior you need.*/
//This particular custom middleware is doing request logging.(recording information about an HTTP request)
//Mainly for debugging, monitoring, and tracking
public class MyMiddleware
{
    private readonly RequestDelegate _next;

    public MyMiddleware(RequestDelegate next)
    {
        _next = next;
    }

    public async Task InvokeAsync(HttpContext context) //Task-the method returns an asynchronous task and HttpContext 
                                                       //context → contains information about the current HTTP request and response
    {
        Console.WriteLine("Before");

        await _next(context); //send req to the next middleware

        Console.WriteLine("After");
    }
}

app.UseMiddleware<MyMiddleware>(); //write in program.cs to register it