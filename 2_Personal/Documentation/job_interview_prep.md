# Job Interview prep

## C# and ASP.NET

### Wat is het verschil tussen een struct en een class in c#?
> - Een struct is een value type → stack.
> - Een class is een reference type → heap.

### Wat zijn interfaces in C# en waarom gebruik je ze?
> een interface definieert een contract of blueprint van members, maar zonder implementatie (wat wel moet op bij de classes die de interface implementeert)

### Leg de termen async en await uit in  C#?
> Deze dienen voor asynchrone code te schrijven. await laat toe om calls te maken naar functies die gedefinieerd zijn met het async sleutelwoord. Asynchrone functies laten je toe om taken uit te voeren zonder de hoofdthread the blokkeren.

### Wat is een lambda expressie in C#?
> Een beknopte manier om anonieme functies te definieren. Dit wordt bv. gebruikt in het configuren van options van services.

```csharp
// example lambda expression
Func<int, int> square = x => x*x;
```

### Wat is het verschil tussen een abstracte klasse en een interface in C#?
> Een abstracte class kan zowel members met als zonder implementatie hebben, terwijl een interface enkel zonder implementatie bevat. abstract classes dienen kunnen niet geinstantieerd worden en dienen voornamelijk als een gedeeld startpunt voor de afgeleide classes.

### Wat zijn static Classes?
> Static classes zijn classes die geen instantie vereissen. Deze bevatten dan allemaal static (niet veranderende) members. Bv. de class Math.

### Hoe werkt garbage collection in C#?
> De garbage collector beheert het geheugen door objecten die niet meer gebruikt worden, automatisch vrij te geven.

### Wat is een delegate in C#?
> Een delegate is een type dat een referentie naar een method opslaat, similar to a pointer.
```csharp
:: example delegate
public delegate void PrintMethod(string message);

public static void HelloWorld(string message)
{
    Console.WriteLine("Hello World");
    Console.WriteLine(message);
}

PrintMethod pm = HelloWorld;
pm("This is a message!"); 
```

### Wat is een nullable type in C#?
> nullable types kunnen een waarde of 'niks', aka 'null' bevatten. types kunnen nullable gemaakt worden met de ? operator.

### Waarvoor dient het 'using' statement?
> using zorgt ervoor dat een object automatisch vrijgegeven wordt wanneer het buiten scope is. Dit voorkomt geheugenlekken en zorgt voor beter resourcebeheer
```csharp
// example of using
using (var file = new StreamWriter("file.txt"))
{
    file.WriteLine("Hello, world!");
}  // StreamWriter wordt automatisch vrijgegeven zodra dit block wordt verlaten
```

### Wat is middleware in asp.net?
> mw zijn componenten in de http-request pipeline die verzoeken en reacties verwerken. voorbeelden hiervan zijn: Logging, Authentication, CORS, Exception Handling.

### Wat is dependency injection?
> dependencies (objects of services) worden aangeleverd (injected) aan de class dat ze nodig heeft ipv. dat een class ze zelf creeert. De instanties van de dependencies worden bijgehouden in een dependency container, ook wel de IoC-Container (Inversion of Control) genoemd.

### Wat is Entity Framework?
> EF is een ORM (Object relational Mapping) waarmee je data kunt beheren als objecten ipv. via SQL queries.

### Wat is het verschil tss `IActionResult` en `ActionResult<T>` in asp.netcore?
> IActionResult kan elke type retourneren (dmv. *Result classes) terwijl een een ActionResult<T> enkel een actie van het type T kan retourneren.

### Wat is een `ModelState` in asp.net?
> In de context van validatie, Modelstate controleert of de verkregen gegevens geldig zijn op basis van de definitie van het model.
```csharp
if (!ModelState.IsValid){
    return BadRequest(ModelState);}
```

### Hoe voeg je authenticatie / authorisatie toe in asp.net?
> Je kan Middleware Components toevoegen zoals AddAuthentication, AddAuthorization, MSAL (MS authentication Lib.)

### Wat zijn Razor Pages?
> Razo pages is een manier om aan web development te doen in asp.net. het is een page-focused framework bovenop asp.net.

### Wat is het verschil tussen `ViewResult` en `JsonResult`?
> Classes die gebruikt worden als return value bij een IActionResult method. ViewResult retourneert een html-view en JsonResult retourneert een JSON-object.

### Hoe implementeer je logging?
> via een middleware component en daarna via dependency injection.

### Wat is Routing in asp.net core?
> mbh. routing kan je bepalen via welke urls welke controller actionmethods aangesproken worden.


<br>
<br>


## React and Typescript

### Wat is het verschil tussen een functionele en een class component in React?
> Components bepalen hoe de UI eruit al zien gebaseerd op state en props. Functionele comps worden tegenwoordig meer gebruikt, dankzij de introductie van hooks. Hierdoor zijn functionele componentts makkelijker en eenvoudiger geworden. Functionele components retourneren JSX.

### Wat is useState in React?
> useState laat je toe om statevariables in functionele componenten te gebruiken.

### Wat is useEffect in React?
> useEffect laat je toe om side-effects (bv data fetching) uit te voeren. Belangrijk is hier dat de code in een useEffect wordt uitgevoerd na de re-render.

### Hoe werkt routing in React met React Router?
> Met React Router kan je URLs definieren om tussen verschillende componenten te navigeren.

### Wat is TypeScript en waarom gebruiken we het met React?
> Typescript is een superset van javascript met typecontrole

### Hoe definieer je een type voor een prop in TypeScript?
> Dit kan via Interfaces of Type-aliases.
```typescript
interface HeaderProps { name: string };

const Header = ({ name } : HeaderProps) => {
return <>hello, {name}</>;
}
```

### Wat is het verschil tussen props en state in React?
> Props worden doorgegeven door parent components terwijl state door de component zelf beheerd wordt.

### Wat is context in React?
> Context laat je toe om globale data zoals thema's of userdata overal beschikbaar te maken. (props zijn dus hier niet nodig)

### Hoe kun je een React app optimizen voor betere prestaties?
> Het doel is om onnodige rerenders te voorkomen. Goed plannen waar je props of hooks gebruikt (ref. useUserManager stageproject!). Gebruik useMemo (memoize a value) en useCallback (memoize a function).

### Hoe gebruik je forms in React?
> Dit kan via State managment of mbhv. libraries (eg. AntD Form Component).

### Wat zijn React Refs en Forward Refs?
> ??

### Wat is het verschil tss let, const en var in TS?
> let en const zijn block scoped, terwijl var function scoped is. const is immutable.

### Wat is een interface in TS?
> Een interface definieert de structuur van een object en geeft aan welke properties en methods het object zou moeten hebben.

### Wat is een union type in TS?
> Union types laten toe om meerdere types toe te kennen aan een variable. Bv. const x : string | number;

### Wat is een tuple in TS?
> Een tuple is een array met een vaste volgorde en type van elementen.
```typescript
let person : [string, number] = ["John", 30];                      // a tuple
let people : [string, number][] =  [["John", 30], ["Amelia", 24]]; // an array of tuples
```

### Wat is het verschil tussen een `type alias` en een `interface`?
> Beide definieren de structuur van een type of object, maar type alias kan meer complexe structuren definieren (zoals unions).

### Hoe werkt Generics in TS?
> Met Generics wordt bedoeld om het sleutelwoord `T` te gebruiken in het coderen van oa. methods en interfaces. Generics maakt code herbruikbaar door types parametrisch te maken.
```typescript
const mapApiResponse = <T>(data:T, error:string, info:string): ApiResponse<T> => {
    return new ApiResponse<T>({
        data:data,
        info:info,
        error:error
    });
};
```

### Wat zijn enums in Typescript?
> enums zijn een makkelijke manier om een verzameling van constante waarden te definieren. bv zoals `enum Weekdays { Sunday = 0, Monday = 1, ...}`

### Wat is `type assertion` in TS?
> met type assertion kan je expliciet aanduiden welke type of interface een waarde heeft dmv. `:` sleutelwoord.

### Hoe definieer je `readonly` eigenschappen in TS?
> Het readonly sleutelwoord zorgt ervoor dat de waarde van een eigenschap niet kan worden gewijzigd. dit moet aangeduid worden in de definitie van de interface.
```typescript
interface User {
    readonly userId:number;
    name: string;
}
```

### Wat is async/await in Typescript?
> Dit zijn syntactische hulpmiddelen voor het schrijven van asynchrone code die gebruik maakt van `Promises`.
```typescript
const GetApiResponse = async (url :string) : Promise<ApiResponse> => {
    const response = await axios.get(url);
    return response;
}
```





