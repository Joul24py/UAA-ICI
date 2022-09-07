using AppCitas.Service.Data;
using AppCitas.Service.Entities;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Http;

namespace AppCitas.Service.Controllers;

[ApiController]
[Route("api/[controller]")]
public class UsersController : ControllerBase
{
    private readonly DataContext _context;

    public UsersController(DataContext context)
    {
        _context = context;
    }

    // GET api/users
    [HttpGet]
    public ActionResult<IEnumerable<AppUser>> GetUsers()
    {
        var users = _context.Users.ToList();
        return users;
    }

    // GET api/users/:id
    [HttpGet("{id}")]
    public ActionResult<AppUser> GetUserById(int id)
    {
        var user = _context.Users.Find(id);
        return user;
    }
}