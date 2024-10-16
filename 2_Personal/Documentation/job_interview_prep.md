←, ↑, →, ↓  Unicode arrows
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
> Een beknopte manier om anonieme functies te definieren.

```csharp
// example lambda expression
Func<int, int> square = x => x*x;
```

### Wat is het verschil tussen een abstracte klasse en een interface in C#?
> Een abstracte class kan zowel members met als zonder implementatie hebben, terwijl een interface enkel zonder implementatie bevat. abstract classes dienen kunnen niet geinstantieerd worden en dienen voornamelijk als een gedeeld startpunt voor de afgeleide classes.

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



