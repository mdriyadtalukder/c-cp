public class MyService
{
    private readonly IRepo _repo;
    public MyService(IRepo repo) //IRepo is injected through the constructor.
    {
        _repo = repo;
    }
}