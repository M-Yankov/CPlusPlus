## Minerals on the Mars.

* Task description:

In the game exists the following objects: Worker, Base, Map, Minerals, Enemy catapult. <br/>
The map is a sample two dimensional array (table N x M). At [0,0] on the map is placed the Base.  <br/>
At bottom-right corner [N - 1, M - 1] there is the enemy catapult. Minerals are placed on random cells on the map. They cannot be placed over the Base or the catapult. <br/>
The Worker starts from the Base and it's task is to bring all minerals to the base. The enemy catapult makes shot 
every 3s to a random cell. One move from one cell to another of the worker costs 1s.<br/>
When the worker is in the base print only the base symbol.<br/>
If the catapult hits the worker - he is returned to the base. Then the Base loses 1 mineral or 20% 
of initial health when there are 0 minerals. <br/>
If the worker holds a mineral while it is hit, the mineral is destroyed and the worker is returned to the base.  <br/>
If the catapult hits just a mineral - nothing happens. The catapult cannot hit directly the Base. <br/>

From the console you will receive N and M one line.
On the second line the numbers of minerals

Constraints:
N and M will be always between 4 and 100 inclusive.
Number of minerals will be less than (N * M) - 4 inclusive. 

Your task:
*   Implement a logic that fills the map with minerals on the random places.  :white_check_mark:
    *   Each start of application minerals should be placed on different cells.  :white_check_mark:
*   Initial health of the Base is 100. :white_check_mark:
*   Worker move costs 1s. :white_check_mark:
*   worker can wear only 1 mineral at time. :white_check_mark:
*   The catapult fires every 3s. :white_check_mark:
*   The catapult and worker should takes its actions in diffrent threads. :white_check_mark:
*   Print the `**Base info**` when worker brings mineral or the worker takes damage. :white_check_mark:
    *   Format "Base X Minerals X Health"   :white_check_mark:
*   Implement a logic for get all minerals on the map. (Don't waste moves). :white_check_mark:
*   Print the map after each move of worker and after each shot of catapult. :white_check_mark:
*   Use  weak (smart) pointer for Base and Worker holds minerals. :white_check_mark:
    *   Base symbol - `B`  :white_check_mark:
    *   Worker symbol - `O` :white_check_mark:
    *   Empty cell - `·`  (middle dot char code 250)  :white_check_mark:
    *   Mineral symbol - `M`  :white_check_mark:
    *   Catapult strikes symbol - `X` :white_check_mark: 
    *   Catapult symbol - `<`  :white_check_mark:
    *   Split cells with one space  :white_check_mark:
*   Clear console before print. :white_check_mark:
*   Implement logic for random fire of catapult. :white_check_mark:
*   The game ends when all minerals are collected or the base is destroyed. :white_check_mark:
*   When game is finished print `**Base info**`. :white_check_mark:

Sample Input:
<pre>
4 4
5
</pre>

Sample output:
<pre>
B · · M
· M · M
· · M ·
M · · <
</pre>
<pre>
B · · M
O M · M
· · M ·
M · · <
</pre>
<pre>
B · · M
· O · M
· · M ·
M · · <
</pre>
<pre>
B · · M
O · · M
· X M ·
M · · <
</pre>
<pre>
B · · M
· · · M
· · M ·
M · · <
Base: 1 Minerals 100 health
</pre>

Success result | Fail result
--- | --- 
![](/06.MemoryManagement/TheMarsMission/Images/TheMarsMissionGif1.gif?raw=true) | ![](/06.MemoryManagement/TheMarsMission/Images/TheMarsMissionFail.gif?raw=true)
