
| Task | Direction | Stack Order |
|----|----|----|
| **Next Greater Right** | Right → Left | Decreasing |
| **Next Greater Left** | Left → Right | Decreasing |
| **Next Smaller Right** | Right → Left | Increasing |
| **Next Smaller Left** | Left → Right | Increasing |

## 📘 How to Remember It:

* If you're finding **next something to the right**, traverse **right → left**
* If you're finding **next something to the left**, traverse **left → right**

And:

* For **greater**, use a **decreasing stack** (keep larger elements on top)
* For **smaller**, use an **increasing stack** (keep smaller elements on top)

## 🔁 Which Direction Should You Traverse?

| Problem Type | Traverse From | Use Stack To Maintain |
|----|----|----|
| **NGR** (Next Greater Right) | Right → Left | **Decreasing stack** (monotonic decreasing) |
| **NGL** (Next Greater Left) | Left → Right | **Decreasing stack** |
| **NSR** (Next Smaller Right) | Right → Left | **Increasing stack** (monotonic increasing) |
| **NSL** (Next Smaller Left) | Left → Right | **Increasing stack** |

practice 4 problem

NSR,NSL,NGR,NGL