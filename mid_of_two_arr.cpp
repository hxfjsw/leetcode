/**
这道题让我们求两个有序数组的中位数，
而且限制了时间复杂度为 O(log (m+n))，
看到这个时间复杂度，自然而然的想到了应该使用二分查找法来求解。
 但是这道题被定义为Hard也是有其原因的，
 难就难在要在两个未合并的有序数组之间使用二分法，
 如果这道题只有一个有序数组，
 让我们求中位数的话，估计就是个 Easy 题。
 那么我们可以将两个有序数组混合起来成为一个有序数组再做吗，
 图样图森破，这个时间复杂度限制的就是告诉你金坷垃别想啦。那
 么我们还是要用二分法，
 而且是在两个数组之间使用，
 感觉很高端啊。
 那么回顾一下中位数的定义，如果某个有序数组长度是奇数，那么其中位数就是最中间那个，如果是偶数，那么就是最中间两个数字的平均值。
 这里对于两个有序数组也是一样的，假设两个有序数组的长度分别为m和n，
 由于两个数组长度之和 m+n 的奇偶不确定，
 因此需要分情况来讨论，对于奇数的情况，直接找到最中间的数即可，
 偶数的话需要求最中间两个数的平均值。

 为了简化代码，不分情况讨论，我们使用一个小 trick，我们分别找第 (m+n+1) / 2 个，和 (m+n+2) / 2 个，然后求其平均值即可，
 这对奇偶数均适用。加入 m+n 为奇数的话，那么其实 (m+n+1) / 2 和 (m+n+2) / 2 的值相等，相当于两个相同的数字相加再除以2，还是其本身。

 好，这里我们需要定义一个函数来在两个有序数组中找到第K个元素，
 下面重点来看如何实现找到第K个元素
 。首先，为了避免产生新的数组从而增加时间复杂度，
 我们使用两个变量i和j分别来标记数组 nums1 和 nums2 的起始位置。


 然后来处理一些 corner cases，比如当某一个数组的起始位置大于等于其数组长度时，说明其所有数字均已经被淘汰了，相当于一个空数组了，那么实际上就变成了在另一个数组中找数字，直接就可以找出来了。还有就是如果 K=1 的话，那么我们只要比较 nums1 和 nums2 的起始位置i和j上的数字就可以了。难点就在于一般的情况怎么处理？因为我们需要在两个有序数组中找到第K个元素，为了加快搜索的速度，我们要使用二分法，那么对谁二分呢，数组么？其实要对K二分，意思是我们需要分别在 nums1 和 nums2 中查找第 K/2 个元素，注意这里由于两个数组的长度不定，所以有可能某个数组没有第 K/2 个数字，所以我们需要先 check 一下，数组中到底存不存在第 K/2 个数字，如果存在就取出来，否则就赋值上一个整型最大值。如果某个数组没有第 K/2 个数字，那么我们就淘汰另一个数组的前 K/2 个数字即可。举个例子来说吧，比如 nums1 = {3}，nums2 = {2, 4, 5, 6, 7}，K=4，我们要找两个数组混合中第4个数字，那么我们分别在 nums1 和 nums2 中找第2个数字，我们发现 nums1 中只有一个数字，不存在第二个数字，那么 nums2 中的前2个数字可以直接跳过，为啥呢，因为我们要求整个混合数组的第4个数字，不管 nums1 中的那个数字是大是小，第4个数字绝不会出现在 nums2 的前两个数字中，所以可以直接跳过。

有没有可能两个数组都不存在第 K/2 个数字呢，这道题里是不可能的，因为我们的K不是任意给的，而是给的 m+n 的中间值，所以必定至少会有一个数组是存在第 K/2 个数字的。最后就是二分法的核心啦，比较这两个数组的第 K/2 小的数字 midVal1 和 midVal2 的大小，如果第一个数组的第 K/2 个数字小的话，那么说明我们要找的数字肯定不在 nums1 中的前 K/2 个数字，所以我们可以将其淘汰，将 nums1 的起始位置向后移动 K/2 个，并且此时的K也自减去 K/2，调用递归。反之，我们淘汰 nums2 中的前 K/2 个数字，并将 nums2 的起始位置向后移动 K/2 个，并且此时的K也自减去 K/2，调用递归即可，参见代码如下：
 */



