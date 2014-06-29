; *** national semiconductor dp83820 ***

; +++ registers definition +++
DP83820_Registers	struc
CR		dd	?	; 00 command
CFG		dd	?	; 04 configuration
MEAR		dd	?	; 08 EEPROM access
PTSCR		dd	?	; 0c PCI test control
ISR		dd	?	; 10 interrupt status
IMR		dd	?	; 14 interrupt mask
IER		dd	?	; 18 interrupt enable
IHR		dd	?	; 1c interruopt holdoff
TXDP		dd	?	; 20 transmit descriptor pointer
TXDP_HI		dd	?	; 24 
TXCFG		dd	?	; 28 transmit configuration
GPIOR		dd	?	; 2c general purpose caontrol
RXDP		dd	?	; 30 receive descriptor pointer
RXDP_HI		dd	?	; 34 
RXCFG		dd	?	; 38 receive configuration
PQCR		dd	?	; 3c priority queueing control
WCSR		dd	?	; 40 Wake on Lan control/status
PCR		dd	?	; 44 pause control/status
RFCR		dd	?	; 48 receive filter/match control
RFDR		dd	?	; 4c receive filter/match data
BRAR		dd	?	; 50 Boot ROM address
BRDR		dd	?	; 54 boot ROM data
SRR		dd	?	; 58 sillicon revision

MIBC		dd	?	; 5c management information base control
MIB_RXErroredPkts dd	?	; 60 MIB
MIB_RXFCSErrors	dd	?	; 64 MIB
MIB_RXMsdPktErrors dd	?	; 68 MIB
MIB_RXFAErrors	dd	?	; 6c MIB
MIB_RXSymbolErrors dd	?	; 70 MIB
MIB_RXFrameTooLong dd	?	; 74 MIB
MIB_RXIRLErrors	dd	?	; 78 MIB
MIB_RXBadOpcodes dd	?	; 7c MIB
MIB_RXPauseFrames dd	?	; 80 MIB
MIB_TXPauseFrames dd	?	; 84 MIB
MIB_TXSQEErrors	dd	?	; 88 MIB

		dd	5 dup(?) ; 8c-9c reserve
TXDP1		dd	?	; a0 txdp priority 1
TXDP2		dd	?	; a4 txdp priority 2
TXDP3		dd	?	; a8 txdp priority 3
		dd	?	; ac 
RXDP1		dd	?	; b0 rxdp priority 1
RXDP2		dd	?	; b4 rxdp priority 2
RXDP3		dd	?	; b8 rxdp priority 3
VRCR		dd	?	; bc VLAN/IP receive control
VTCR		dd	?	; c0 VLAN/IP transmit control
VDR		dd	?	; c4 VLAN data
		dd	?	; c8 
CCSR		dd	?	; cc CLKRUN control/status
		dd	4 dup(?) ; d0-dc
TBICR		dd	?	; e0 TBI control
TBISR		dd	?	; e4 TBI status
TANAR		dd	?	; e8 TBI auto-negotiation advertise
TANLPAR		dd	?	; ec TBI auto-negotiation Link Partner Ability
TANER		dd	?	; f0 TBI auto-negotiation expantion
TESR		dd	?	; f4 TBI extended status
		dd	2 dup(?) ; f8,fc
DP83820_Registers	ends

; +++ command register +++
RXPRI3		equ	10000h	; rx queue priority 3 select
RXPRI2		equ	 8000h	; rx queue priority 2 select
RXPRI1		equ	 4000h	; rx queue priority 1 select
RXPRI0		equ	 2000h	; rx queue priority 0 select
TXPRI3		equ	 1000h	; tx queue priority 3 select
TXPRI2		equ	  800h	; tx queue priority 2 select
TXPRI1		equ	  400h	; tx queue priority 1 select
TXPRI0		equ	  200h	; tx queue priority 0 select
RST		equ	  100h	; reset
SWIR		equ	   80h	; software interrupt
RXR		equ	   20h	; receiver reset
TXR		equ	   10h	; transmit reset
RXD		equ	    8	; receiver disable
RXE		equ	    4	; receiver enable
TXD		equ	    2	; transmit disable
TXE		equ	    1	; transmit enable

; +++ configuration and media status register +++
LNKSTS		equ	80000000h	; link status
SPDSTS1		equ	40000000h	; speed status 1000
SPDSTS0		equ	20000000h	; speed status 100
DUPSTS		equ	10000000h	; full duplex status
TBI_EN		equ	 1000000h	; TBI enable
MODE_1000	equ	  400000h	; enable 1000Mb/s mode
PINT_CTL_DUP	equ	  100000h	; phy interrupt control - duplex
PINT_CTL_LNK	equ	   80000h	; phy interrupt control - link
PINT_CTL_SPD	equ	   40000h	; phy interrupt control - speed
TMRTEST		equ	   20000h	; timer test mode (100us to 4us)
MRM_DIS		equ	   10000h	; memory read multiple disable
MWI_DIS		equ	    8000h	; memory write and invalidate disable
T64ADDR		equ	    4000h	; target 64bit addressing enable
PCI64_DET	equ	    2000h	; PCI 64bit bus detected
DATA64_EN	equ	    1000h	; 64bit data enable
M64ADDR		equ	     800h	; master 64bit addressing enable
PHY_RST		equ	     400h	; reset phy
PHY_DIS		equ	     200h	; disable phy
EXTSTS_EN	equ	     100h	; extended status enable
REQALG		equ	      80h	; PCI bus request algorithm
SB		equ	      40h	; single back-off
POW		equ	      20h	; program out of window timer
EXD		equ	      10h	; excessive deferral abort
PESEL		equ	       8	; parity error detection action
BROM_DIS	equ	       4	; disable boot rom interface
EXT_125		equ	       2	; external 125MHz reference select
BEM		equ	       1	; big endian mode

; +++ EEPROM access register +++
MDC		equ	40h	; MII management clock
MDDIR		equ	20h	; MII managemant direction
MDIO		equ	10h	; MII management data
EESEL		equ	 8	; EEPROM chip select
EECLK		equ	 4	; EEPROM serial clock
EEDO		equ	 2	; EEPROM data out
EEDI		equ	 1	; EEPROM data in

; +++ interrupt status/mask register +++
TXDESC3		equ	40000000h	; tx descriptor priority 3
TXDESC2		equ	20000000h	; tx descriptor priority 2
TXDESC1		equ	10000000h	; tx descriptor priority 2
TXDESC0		equ	 8000000h	; tx descriptor priority 0
RXDESC3		equ	 4000000h	; rx descriptor priority 3
RXDESC2		equ	 2000000h	; rx descriptor priority 2
RXDESC1		equ	 1000000h	; rx descriptor priority 1
RXDESC0		equ	  800000h	; rx descriptor priority 0
TXRCMP		equ	  400000h	; transmit reset complete
RXRCMP		equ	  200000h	; receive reset complete
DPERR		equ	  100000h	; detectd parity error
SSERR		equ	   80000h	; signaled system error
RMABT		equ	   40000h	; receive master abort
RTABT		equ	   20000h	; receive target abort
RXSOVR		equ	   10000h	; rx status FIFO overrun
HIBINT		equ	    8000h	; high bit interrupt set
PHY		equ	    4000h	; phy interrupt
PME		equ	    2000h	; power management event
SWI		equ	    1000h	; software interrupt
MIB		equ	     800h	; MIB service
TXURN		equ	     400h	; tx underrun
TXIDLE		equ	     200h	; tx idle
TXERR		equ	     100h	; tx packet error
TXDESC		equ	      80h	; tx descriptor
TXOK		equ	      40h	; tx packet ok
RXORN		equ	      20h	; rx overrun
RXIDLE		equ	      10h	; rx idle
RXEARLY		equ	       8	; rx early threshold
RXERR		equ	       4	; rx packet error
RXDESC		equ	       2	; rx descriptor
RXOK		equ	       1	; rx ok

; +++ interrupt enable register +++
IE		equ	1	; interrupt enable

; +++ interrupt holdoff register +++
IHCTL		equ	100h	; interrupt holdoff control
IH		equ	0ffh	; interrupt holdoff (mask)

; +++ transmit configuration register +++
CSI		equ	80000000h	; carrier sense ignore
HBI		equ	40000000h	; heartbeat ignore
MLB		equ	20000000h	; MAC loopback
ATP		equ	10000000h	; automatic transmit padding
ECRETRY		equ	  800000h	; excessive collision retry enable
TxMXDMA		equ	  700000h	; max DMA burst size per tx DMA burst (mask)
BRST_DIS	equ	   80000h	; 1000Mb/s burst disable
TxFLTH		equ	   0ff00h	; tx fill threshold (mask)
TxDRTH		equ	     0ffh	; tx drain threshold (mask)

; +++ receive configuration register +++
AEP		equ	80000000h	; accept errored packets
ARP		equ	40000000h	; accept runt packets
STRIPCRC	equ	20000000h	; strip CRC
RX_FD		equ	10000000h	; accept transmit packets
ALP		equ	 8000000h	; accept long packets
AIRL		equ	 4000000h	; accept in-range length errord packet
RxMXDMA		equ	  700000h	; max DMA burst size per rx DMA burst (mask)
RxDRTH		equ	      3eh	; rx drain threshold (mask)

; +++ priority queueing control register +++
RXPQ		equ	0ch	; receive priority queue enable (mask)
TXFAIR		equ	 2	; transmit fairness enable
TXPQEN		equ	 1	; transmit priority queue enable

; +++ pause control/status register +++
PSEN		equ	80000000h	; pause enable
PS_MCAST	equ	40000000h	; pause on multicast
PS_DA		equ	20000000h	; pause on DA
PS_ACT		equ	10000000h	; pause active
PS_RCVD		equ	 8000000h	; pause frame received
PS_STHI		equ	 3000000h	; rx stat FIFO hi threshold (mask)
PS_STLO		equ	 0c00000h	; rx stat FIFO lo threshold (mask)
PS_FFHI		equ	  300000h	; rx data FIFO hi threshold (mask)
PS_FFLO		equ	  0c0000h	; rx data FIFO lo threshold (mask)
PS_TX		equ	   40000h	; transmit pause frame
PAUSE_CNT	equ	   0ffffh	; pause control value (mask)

; +++ receive filter/match control register +++
RFEN		equ	80000000h	; rx filter enable
rfAAB		equ	40000000h	; accept all broadcast
rfAAM		equ	20000000h	; accept all multicast
rfAAU		equ	10000000h	; accept all unicast
rfAPM		equ	 8000000h	; accept on perfect match
rfAPAT		equ	 7800000h	; accept on pattern match (mask)
rfAARP		equ	  400000h	; accept ARP packets
rfMHEN		equ	  200000h	; multicast hash enable
rfUHEN		equ	  100000h	; unicast hash enable
rfULM		equ	   80000h	; U/L bit mask
RFADDR		equ	     3ffh	; receive filter extended register address

; +++ receive filter/match data register +++
BMASK		equ	   30000h	; byte mask
RFDATA		equ	   0ffffh	; receive filter data (mask)

; +++ management information base control register +++
MIBS		equ	8	; MIB counter strobe
ACLR		equ	4	; clear all counters
FRZ		equ	2	; freeze all counters
WRN		equ	1	; warning test indicator

; +++ VLAN/IP receive control register +++
RUDPE		equ	80h	; reject UDP checksum errors
RTCPE		equ	40h	; reject TCP checksum errors
RIPE		equ	20h	; reject IP checksum errors
IPEN		equ	10h	; IP checksum enable
DUTF		equ	 8	; discard untagged frames
DVTF		equ	 4	; discard VLAN tagged frames
VTREN		equ	 2	; VLAN tag removal enable
VTDEN		equ	 1	; VLAN tag detection enable

; +++ VLAN/IP transmit control register +++
PPCHK		equ	8	; per packet checksum generation
GCHK		equ	4	; global checksum generation
VPPTI		equ	2	; VLAN per packet tag insertion
VGTI		equ	1	; VLAN global tag insertion

; +++ VLAN data register +++
VTCI		equ	0ffff0000h	; VLAN tag control information field
VTYPE		equ	    0ffffh	; VLAN type field

; +++ CLKRUN control/status register +++
PMESTS		equ	8000h	; PME status
PMEEN		equ	 100h	; PME enable
CLKRUN_EN	equ	   1	; clkrun enable


; +++ buffer +++
bufdesc		struc
link		dd	?	; next descriptor link
bufptr		dd	?	; buffer pointer
cmdsts		dd	?	; command/status field
extsts		dd	?	; extended status field
; above for device, below for driver.
phyaddr		dd	?	; physical address of this descriptor
virtaddr	dd	?	; virtual address of bufptr (rx)
deschandle	dw	?	; descriptor handle (rx)
desctail	dw	?	; frame tail descriptor (rx)
vlink		dw	?	; virtual link
		dw	?	; reserve for dword alignment
bufdesc		ends

; +++ cmdsts bit +++
OWN		equ	80000000h	; descriptor ownership
MORE		equ	40000000h	; more descriptor
INTR		equ	20000000h	; interrupt
SUPCRC		equ	10000000h	; tx suppress CRC
INCCRC		equ	10000000h	; rx inclued CRC
OK		equ	 8000000h	; packet OK
BUFSIZE		equ	    0fffh	; descriptor byte count

; +++ transmit status bit +++
TXA		equ	 4000000h	; transmit abort
TFU		equ	 2000000h	; transmit FIFO underrun
CRS		equ	 1000000h	; carrier sense lost
TD		equ	  800000h	; transmit deferred
ED		equ	  400000h	; excessive defferred
OWC		equ	  200000h	; out of window collision
EC		equ	  100000h	; excessive collisions
CCNT		equ	  0f0000h	; collision count

; +++ receive status bit +++
RXA		equ	 4000000h	; receive aborted
RXO		equ	 2000000h	; receive overrun
DEST		equ	 1800000h	; destination class
LONG		equ	  400000h	; too long packet received
RUNT		equ	  200000h	; runt packet received
ISE		equ	  100000h	; invalid symbol error
CRCE		equ	   80000h	; CRC error
FAE		equ	   40000h	; frame alignment error
LBP		equ	   20000h	; loopback packet
IRL		equ	   10000h	; collision activity

; +++ extsts bit +++
UDPERR		equ	400000h		; UDP checksum error (rx)
UDPPKT		equ	200000h		; UDP packet (tx/rx)
TCPERR		equ	100000h		; TCP checksum error (rx)
TCPPKT		equ	 80000h		; TCP packet (tx/rx)
IPERR		equ	 40000h		; IP checksum error (rx)
IPPKT		equ	 20000h		; IP packet (tx/rx)
VPKT		equ	 10000h		; VLAN packet (tx/rx)
exVTCI		equ	 0ffffh		; VLAN tag control information

; +++ virtual tx frame descriptor (for driver) +++
txdesc		struc
deschead	dw	?	; head descriptor
desctail	dw	?	; tail descriptor
reqhandle	dw	?	; requset handle
protid		dw	?	; protocol id
vlink		dw	?	; vlink
		dw	?	; reserve
immedphy	dd	?	; physical address of immediate data
immed		db	64 dup (?) ; reserve for immediate data
txdesc		ends

